#!/usr/bin/python
import sys, os
 
print ("Content-Type: text/html\r\n\r\n");
for name, value in os.environ.items():
         print ("%s\t= %s" % (name, value));
         print("\n");