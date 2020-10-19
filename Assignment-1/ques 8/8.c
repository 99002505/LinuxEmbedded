#define THREAD_COUNT 4
#define ARRAY_SIZE 400
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int arr[ARRAY_SIZE];
void fillArray(void);

struct ThreadParameters
{
    // input
    int* array;
    int start;
    int end;

    // output
    int small;
    int large;
};
void* find_min_max(void* args)
{
    struct ThreadParameters* params = (struct ThreadParameters*)args;
    int *array = params->array;
    int start = params->start;
    int end = params->end;
    int small = array[start];
    int large = array[start];


    for (int i = start; i < end; i++)
    {
        if (array[i] < small)
        {
            small = array[i];
        }

        if (array[i] > largest)
        {
            large = array[i];
        }
    }

    // write the result back to the parameter structure

    params->small = small;
    params->large = large;

    return 0;
}
void fillArray()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

int main()
{
    int small;
    int large;

    // declare an array of threads and associated parameter instances
    pthread_t threads[THREAD_COUNT] = {0};
    struct ThreadParameters thread_parameters[THREAD_COUNT]  = {0};

    // intialize the array    
    fillArray();

    // smallest and largest needs to be set to something
    small = arr[0];
    large = arr[0];

    // start all the threads
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thread_parameters[i].array = arr;
        thread_parameters[i].start = i * (ARRAY_SIZE / THREAD_COUNT);
        thread_parameters[i].end = (i+1) * (ARRAY_SIZE / THREAD_COUNT);
        thread_parameters[i].largest = 0;
        pthread_create(&threads[i], 0, find_min_max, &thread_parameters[i]);
    }

    // wait for all the threads to complete
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], 0);
    }

    // Now aggregate the "smallest" and "largest" results from all thread runs    
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (thread_parameters[i].small < small)
        {
            smallest = thread_parameters[i].smallest;
        }

        if (thread_parameters[i].large > large)
        {
            large = thread_parameters[i].large;
        }
    }

    printf("Minimum element is %d\n", smalle);
    printf("Maximum element is %d\n", large);

}
