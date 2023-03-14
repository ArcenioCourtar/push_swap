# push_swap
My submission for the push_swap project, part of the curriculum of Codam, and other schools part of the 42 Network.

My solution revolves around finding the Longest Increasing Subsequence (LIS for short) within the supplied list with a Patience Sort. 
It then pushes everything that's not part of the LIS gtom `a` to `b` and calculates the quickest way to get all elements back into `b`, one element at a time.

100 random numbers take around 520-610 instructions to put in order.
500 random numbers take around 4800-5300 instructions.

# Possible optimizations:
- [ ] Overhaul the way I perform the Patience Sort and keep track of the stacks. 
You don't need to keep track of all elements in a stack, only the top element of each stack. 
Currently I keep track of all elements in each stack leading to more pointers than necessary.
This is the main bottleneck causing it to take a while calculating stacks with a thousand or more numbers.
- [ ] Extend the LIS on the fly when pushing non-LIS elements to `b` by looking if swapping elements in `a` would "extend" said LIS.
- [ ] In case of a tie in the # of instructions necessary for several instruction combinations, find out which instruction set would lead to the most favorable list positions afterwards.
