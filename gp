#!/bin/sh
git add $1 $2 sort.h
git commit -m "$3"
git push
