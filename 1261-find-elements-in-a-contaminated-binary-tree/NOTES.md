find() can be improved to o(1) space and o(logn) tc.
​
suppose target=4.
You take target+1=5.
suppose tree is       0
1      2
3       5   6
binary of 5 is 101 take n-1 bits from lsb side. You get : 01
Now iterate 01 .
You find 0 so go left. so you reach 1
Next you find 1 so go right. so you reach NULL .
Hence it means 4 is not present.
​