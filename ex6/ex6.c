// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the 
// `clock_gettime` procedure to time how long a single system call takes. It'll 
// do this for one million iterations, and then find the average of all of those 
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
// While the linked site does say that `clock_gettime()` does not work on OSX, this 
// turns out to only be the case for OSX versions < 10.12. Anything later than that 
// and `clock_gettime()` should work just fine. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

// int main()
// {
//     double diff; 
//     struct timespec start, end;

//     // starts the clock
//     clock_gettime(CLOCK_MONOTONIC, &start);
    
//     for (int i = 0; i < number_iter; i++) {
//     // put sys call here
//     write(1, NULL, 0);
//     }
    
//     // stops the clock
//     clock_gettime(CLOCK_MONOTONIC, &end);

//     //perform your calculation
//     diff = (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec)/number_iter;

//     // must type cast diff as llu
//     printf("The average time elapsed was: %llu nanoseconds\n", (long long unsigned int) diff);
    
//     return 0;
// }

int main() 
{
    struct timespec startTime, endTime;
    long sum = 0;
    double avg;

    for (int i = 0; i < number_iter; i++) {
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        
        write(1, NULL, 0);

        clock_gettime(CLOCK_MONOTONIC, &endTime);

        long difference = BILLION * (endTime.tv_sec - startTime.tv_sec) + endTime.tv_nsec - startTime.tv_nsec;
        sum += difference;
    }

    avg = sum / (float)number_iter;

    printf("Average time it takes to make a sys call is: %f", avg);

    return 0;
}