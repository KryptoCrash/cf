/*
NOTES:
Fix two points for query at random in the current segment
there are 3 options for the median
if the first one is the median, the point is to the leftmost segment
if the second one is the median, the point is to the rightmost segment
if the query point is the median, the point is in the middle segment

IF NO POINTS ARE IN THE MIDDLE SEGMENT, THAN THE FIXED POINTS ARE ADJ
IF NO POINTS ARE IN THE LEFTMOST SEGMENT, THAN THE FIRST ONE IS THE LEFTMOST POINT
IF NO POINTS ARE IN THE RIGHTMOST SEGMENT, THAN THE SECOND ONE IS THE RIGHTMOST POINT

run ternary search on each segment

*/