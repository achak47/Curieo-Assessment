# Curieo-Assessment
This contains the online assessment by curieo , the problem statement is to create an error log 

I have used two maps for storing the error logs , both of these maps have a key as the log type of the error . The logs map value stores an array of log details each log belonging to the log type of the key , each element of this array stores the average upto this index , the min upto this index , the max upto this index . These are useful in calculating the before function in O(logN) time , the logsid map is used to find the index of a timestamp using lower bound method and we use this index to get the before value from the original logs map .
add function :- adds the new log to the two maps and the two arrays 
log_type :- takes a log type and uses it as a key in the logs map to find the average , min , max , the last entry of the array is required
before :- this takes the log_type , finds the array belonging to this type from the logs map , now it uses the timestamp to find the index of the latest log which occured before this using the logs id map , now this index is used to get the mean , min , max . Binary search is used which gives us O(logN) time 
after :- this takes the log_type , finds the array belonging to this type from the logs map , now it uses the timestamp to find the index of the earliest log which occured after this using the logs id map , now it checks linearly till the last element for the min , max value this takes O(1) time .
glogs , glogsid are used to store all the logs of all the types together , this is used in finding before and after of all the logs independent of types

Time complexity : 
for Before operations --> O(log N)
for After Operations --> O(N)
for insertion --> O(1)

How to run it ?
Give the input in input.txt file , run the main.cpp , the error_log.h is the header file which contains the designed class
