/*************************************************************************
 * --------------------------------------------------------------------- *            
 *  name:      prime number finder benchmark                             *
 *  author:    Sukdol Jakub                                              *                         
 *  date:      04/04/2021                                                *
 * --------------------------------------------------------------------- *
 ************************************************************************* 
 * 
 *  description:
 *   - benchark the computer by time spent on a task
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define SIEVE_SIZE 1000000
#define NUMBER_OF_PRIMES_IN_A_MILLION 78498

#define TIME_THRESHOLD 20000.0

void get_prime_numbers(int primes[]);

void *thr1();
void *thr2();
void *thr3();
void *thr4();
void *thr5();

int primes1[NUMBER_OF_PRIMES_IN_A_MILLION];
int primes2[NUMBER_OF_PRIMES_IN_A_MILLION];
int primes3[NUMBER_OF_PRIMES_IN_A_MILLION];
int primes4[NUMBER_OF_PRIMES_IN_A_MILLION];
int primes5[NUMBER_OF_PRIMES_IN_A_MILLION];

int main(int argc, char *argv[])
{
    clock_t mem = clock();
    int primes[NUMBER_OF_PRIMES_IN_A_MILLION] = {0};
    for (int i = 0; i < NUMBER_OF_PRIMES_IN_A_MILLION; ++i) {
        primes1[i] = 0;
        primes2[i] = 0;
        primes3[i] = 0;
        primes4[i] = 0;
        primes5[i] = 0;
    }
    // initialize array of integers to zeros

    long long  int diff = clock() - mem;

    float score = (TIME_THRESHOLD - diff * 1.0)/100;

    printf("Memory access score is %f\n", score);

    long long int time_spent = 0;

    printf("TESTING SINGLE THREAD PERFORMANCE ... 0%% done\r");

    for (int i = 0; i < 1000; ++i) {

        clock_t start = clock();
        get_prime_numbers(primes);
        // fill this array with primes
        clock_t difference = clock() - start;
        time_spent += difference;

        if (i%10 == 0) {
            printf("TESTING SINGLE THREAD PERFORMANCE ... %d%% done\r",i/10);
        }
    }

    score = (TIME_THRESHOLD - time_spent * 1.0 / 1000)/100;

    printf("Single thread  computation performance of this device is: %3f\n", score);


    void* (*thr_fuction[])(void *) = {  thr1, thr2, thr3, thr4,thr5 };

    pthread_t threads[5];
    // create all threads
    for (int i = 0; i < 5; ++i) {
        int err = pthread_create(&threads[i], NULL, thr_fuction[i], NULL);
    }
    clock_t new_start = clock();

    // close all threads
    for (int i = 0; i < 5; ++i) {
        int err = pthread_join(threads[i], NULL);
    }
    clock_t difference = clock() - new_start;

    time_spent = difference;
    score = (TIME_THRESHOLD - time_spent * 1.0 / 1000)/100;
    printf("\rMulti thread computation performance of this device is: %3f\n", score);

    return 0;
}

void get_prime_numbers(int primes[])
{
    bool sieve[SIEVE_SIZE];
    // Erastothenes sieve
    for (int i = 0; i < SIEVE_SIZE; ++i) {
        // initialize all values in sieve to boolean true
        sieve[i] = true;
    }

    for (int i = 2; i * i < SIEVE_SIZE; ++i) {
        // initialize boolean values in sieve so that
        // true are on prime numer indexes
        if (sieve[i] == true) {
            for (int j = i * i; j < SIEVE_SIZE; j += i) {
                sieve[j] = false;
            }
        }
    }

    int primes_index = 0;
    for (int i = 2; i < SIEVE_SIZE; ++i) {
        // finally fill array primes with prime numbers
        if (sieve[i] == true) {
            primes[primes_index++] = i;
        }
    }
}

void *thr1()
{

    for (int i = 0; i < 200; ++i) {
        bool sieve[SIEVE_SIZE];
        // Erastothenes sieve
        for (int i = 0; i < SIEVE_SIZE; ++i) {
            // initialize all values in sieve to boolean true
            sieve[i] = true;
        }

        for (int i = 2; i * i < SIEVE_SIZE; ++i) {
            // initialize boolean values in sieve so that
            // true are on prime numer indexes
            if (sieve[i] == true) {
                for (int j = i * i; j < SIEVE_SIZE; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int primes_index = 0;
        for (int i = 2; i < SIEVE_SIZE; ++i) {
            // finally fill array primes with prime numbers
            if (sieve[i] == true) {
                primes1[primes_index++] = i;
            }
        }
    }
}

void *thr2()
{

    for (int i = 0; i < 200; ++i) {
        bool sieve[SIEVE_SIZE];
        // Erastothenes sieve
        for (int i = 0; i < SIEVE_SIZE; ++i) {
            // initialize all values in sieve to boolean true
            sieve[i] = true;
        }

        for (int i = 2; i * i < SIEVE_SIZE; ++i) {
            // initialize boolean values in sieve so that
            // true are on prime numer indexes
            if (sieve[i] == true) {
                for (int j = i * i; j < SIEVE_SIZE; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int primes_index = 0;
        for (int i = 2; i < SIEVE_SIZE; ++i) {
            // finally fill array primes with prime numbers
            if (sieve[i] == true) {
                primes2[primes_index++] = i;
            }
        }
    }
}

void *thr3()
{

    for (int i = 0; i < 200; ++i) {
        bool sieve[SIEVE_SIZE];
        // Erastothenes sieve
        for (int i = 0; i < SIEVE_SIZE; ++i) {
            // initialize all values in sieve to boolean true
            sieve[i] = true;
        }

        for (int i = 2; i * i < SIEVE_SIZE; ++i) {
            // initialize boolean values in sieve so that
            // true are on prime numer indexes
            if (sieve[i] == true) {
                for (int j = i * i; j < SIEVE_SIZE; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int primes_index = 0;
        for (int i = 2; i < SIEVE_SIZE; ++i) {
            // finally fill array primes with prime numbers
            if (sieve[i] == true) {
                primes3[primes_index++] = i;
            }
        }
    }
}

void *thr4()
{

    for (int i = 0; i < 200; ++i) {
        bool sieve[SIEVE_SIZE];
        // Erastothenes sieve
        for (int i = 0; i < SIEVE_SIZE; ++i) {
            // initialize all values in sieve to boolean true
            sieve[i] = true;
        }

        for (int i = 2; i * i < SIEVE_SIZE; ++i) {
            // initialize boolean values in sieve so that
            // true are on prime numer indexes
            if (sieve[i] == true) {
                for (int j = i * i; j < SIEVE_SIZE; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int primes_index = 0;
        for (int i = 2; i < SIEVE_SIZE; ++i) {
            // finally fill array primes with prime numbers
            if (sieve[i] == true) {
                primes4[primes_index++] = i;
            }
        }
    }
}

void *thr5()
{

    for (int i = 0; i < 200; ++i) {
        bool sieve[SIEVE_SIZE];
        // Erastothenes sieve
        for (int i = 0; i < SIEVE_SIZE; ++i) {
            // initialize all values in sieve to boolean true
            sieve[i] = true;
        }

        for (int i = 2; i * i < SIEVE_SIZE; ++i) {
            // initialize boolean values in sieve so that
            // true are on prime numer indexes
            if (sieve[i] == true) {
                for (int j = i * i; j < SIEVE_SIZE; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int primes_index = 0;
        for (int i = 2; i < SIEVE_SIZE; ++i) {
            // finally fill array primes with prime numbers
            if (sieve[i] == true) {
                primes5[primes_index++] = i;
            }
        }
    }
}
