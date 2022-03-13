Easy But Many edge cases:-
​
Let say k=4 and [5,2,2,4,6]. Remove 5,2,2 and going to remove 4 but check is next to 4 greater than all removed ones ( 6> 5,2,2,4) so remove 4 as well and [6] is final answer.
​
Let say k=0 and [5,2,2,4,0,6]. Nothing to remove print top() -->5.
​
Let say k=1000 and [5]. k is even so print 5.
​
Let say k=101 and [5]. k is odd so print -1.