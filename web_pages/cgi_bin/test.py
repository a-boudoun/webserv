#!/usr/bin/python
import sys, os
 
print ("Content-Type: text/html\n\n");
for name, value in os.environ.items():
         print ("%s\t= %s" % (name, value))