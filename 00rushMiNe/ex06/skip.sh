#!/bin/sh
ls -l | awk '{if (NR%2==0) print $0}'
