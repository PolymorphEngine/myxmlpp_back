#!/usr/bin/python

import os

DOXYGEN_OUTPUT_DIR = "doxygen"


os.system("mkdir -p " + DOXYGEN_OUTPUT_DIR)
os.system("doxygen Doxyfile")
