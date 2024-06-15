#Phương thức Strip trong Python loại bỏ hoặc cắt bớt các ký tự đã cho từ đầu và cuối của chuỗi gốc. 
#Hành vi mặc định của phương thức strip() là loại bỏ khoảng trắng ở đầu và cuối chuỗi. \

#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    
    n = int(input().strip())
    
    if(n % 2 != 0):
        print('Weird')
    else: 
        if n in range(2,5):
            print('Not Weird')
            
        elif(n >= 6 and n <= 20 and n % 2 == 0):
            print('Weird')
            
        elif(n > 20 and n % 2 == 0):
            print('Not Weird')
