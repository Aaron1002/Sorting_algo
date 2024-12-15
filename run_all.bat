g++ bucket_sort.cpp -o bucket
g++ counting_sort.cpp -o counting
g++ heap_sort.cpp -o heap
g++ insertion_sort.cpp -o insertion
g++ LSD_radix_sort.cpp -o LSD_radix
g++ merge_sort.cpp -o merge
g++ quick_sort.cpp -o quick

for /l %%s in (1,1,20) do (
    echo 0 10000 1 10000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 10000 10000 30000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 10000 1 30000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 50000 1 50000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 50000 20000 70000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 50000 1 70000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 100000 1 100000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 100000 50000 150000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)

for /l %%s in (1,1,20) do (
    echo 0 100000 1 150000 %%s > input.txt
    bucket.exe < input.txt >> results.txt ^
    counting.exe < input.txt >> results.txt ^
    heap.exe < input.txt >> results.txt ^
    insertion.exe < input.txt >> results.txt ^
    LSD_radix.exe < input.txt >> results.txt ^
    merge.exe < input.txt >> results.txt ^
    quick.exe < input.txt >> results.txt ^
)