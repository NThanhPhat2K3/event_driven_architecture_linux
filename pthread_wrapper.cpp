/**
 * @file pthread_wrapper.c
 * @brief Implementation of a lightweight wrapper around POSIX pthreads.
 *
 * This module simplifies thread creation, joining, and priority configuration.
 *
 * -----------------------------
 *  FEATURES
 * -----------------------------
 *  - Initialize thread wrapper
 *  - Start a thread with a user-defined entry function
 *  - Join a running thread safely
 *  - Configure thread priority and scheduling policy
 *
 * -----------------------------
 *  CONVENTIONS
 * -----------------------------
 *  All functions return:
 *      RET_OK  -> success
 *      RET_NG  -> failure (invalid input, thread already started, pthread
 * error)
 *
 *  This helps simplify upper-layer logic in event-driven architectures.
 */

#include "pthread_wrapper.h"

#include <sched.h>
#include <string.h>

int pthread_wrapper_init(thread_wrapper_t *pthread_wrapper) {
	int ret = RET_OK;

	if(NULL == pthread_wrapper || NULL == pthread_wrapper->entry) {
		ret = RET_NG;
		return ret;
	}

	pthread_wrapper->started = false;

	return ret;
}

int pthread_wrapper_start(thread_wrapper_t *pthread_wrapper) {
	int ret = RET_OK;

	if(NULL == pthread_wrapper) {
		ret = RET_NG;
		return ret;
	}

	if(true == pthread_wrapper->started) {
		ret = RET_NG;
		return ret;
	}

	if(NULL == pthread_wrapper->entry) {
		ret = RET_NG;
		return ret;
	}

	int status = pthread_create(&pthread_wrapper->thread, NULL,
								pthread_wrapper->entry, pthread_wrapper->arg);

	if(0 != status) {
		ret = RET_NG;
		return ret;
	}

	pthread_wrapper->started = true;

	return ret;
}

int pthread_wrapper_join(thread_wrapper_t *pthread_wrapper) {
	int ret = RET_OK;

	if(NULL == pthread_wrapper) {
		ret = RET_NG;
		return ret;
	}

	if(false == pthread_wrapper->started) {
		ret = RET_NG;
		return ret;
	}

	int status = pthread_join(pthread_wrapper->thread, NULL);

	if(0 != status) {
		ret = RET_NG;
		return ret;
	}

	pthread_wrapper->started = false;

	return ret;
}

int pthread_wrapper_set_priority(thread_wrapper_t *pthread_wrapper, int policy,
								 int priority) {
	int ret = RET_OK;

	if(NULL == pthread_wrapper) {
		ret = RET_NG;
		return ret;
	}

	if(false == pthread_wrapper->started) {
		ret = RET_NG;
		return ret;
	}

	struct sched_param param;
	memset(&param, 0, sizeof(param));
	param.sched_priority = priority;

	int status = pthread_setschedparam(pthread_wrapper->thread, policy, &param);

	if(0 != status) {
		ret = RET_NG;
	}

	return ret;
}