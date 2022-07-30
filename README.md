# QuickSelect
Somehow I just now discovered this algorithm and thought it was cool so I took a shot at implementing it.

Nothing terribly fancy, probably only supports distinct numbers, also only using last element as the pivot so not doing anything super intelligent here.

# What is it?
If you're like me living under a rock, the quickselect algorithm can find the k-th largest (or smallest) item in an unsorted array. This can be used to compute medians in linear time (on average). Its implementation is extremely similar to quicksort where a partition is involved using a pivot and recursively traversed.
