/**
 * @file pthread_wrapper.h
 * @brief Minimal wrapper around POSIX pthreads for simplified thread control.
 *
 * @author
 *    NThanhPhat2K3
 */

#ifndef __PTHREAD_WRAPPER_H__
#define __PTHREAD_WRAPPER_H__

#include <pthread.h>
#include <stdbool.h>

#define RET_OK 1
#define RET_NG 0

/**
 * @brief Thread entry function type.
 *
 * The thread function must accept a void pointer as argument
 * and return a void pointer, identical to pthread entry signature.
 */
typedef void *(*pthread_entry_t)(void *arg);

/**
 * @brief Wrapper structure holding thread metadata and state.
 */
typedef struct {
	pthread_t thread;	   /**< pthread handle */
	bool started;		   /**< true if the thread is running */
	pthread_entry_t entry; /**< thread entry function */
	void *arg;			   /**< argument passed to entry */
} thread_wrapper_t;

/**
 * @brief Initialize the thread wrapper.
 *
 * @param pthread_wrapper Pointer to the wrapper instance.
 *
 * @return RET_OK on success, RET_NG on invalid argument.
 */
int pthread_wrapper_init(thread_wrapper_t *pthread_wrapper);

/**
 * @brief Start the thread.
 *
 * @param pthread_wrapper Pointer to initialized wrapper.
 *
 * @return RET_OK on success, RET_NG otherwise.
 */
int pthread_wrapper_start(thread_wrapper_t *pthread_wrapper);

/**
 * @brief Join the running thread.
 *
 * @param pthread_wrapper Pointer to wrapper.
 *
 * @return RET_OK on success, RET_NG on invalid state or error.
 */
int pthread_wrapper_join(thread_wrapper_t *pthread_wrapper);

/**
 * @brief Set scheduling policy and priority for the running thread.
 *
 * Supported policies: SCHED_FIFO, SCHED_RR, SCHED_OTHER.
 * Note: SCHED_FIFO and SCHED_RR typically require root privileges.
 *
 * @param pthread_wrapper Pointer to wrapper.
 * @param policy          Scheduling policy.
 * @param priority        Scheduling priority (policy-dependent).
 *
 * @return RET_OK on success, RET_NG on failure.
 */
int pthread_wrapper_set_priority(thread_wrapper_t *pthread_wrapper, int policy,
								 int priority);

#endif /* __PTHREAD_WRAPPER_H__ */
