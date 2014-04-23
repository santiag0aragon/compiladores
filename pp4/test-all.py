#!/bin/python
#
# File: test-all.py
# Authors: Leonid Shamis (leonid.shamis@gmail.com)
#          Keith Schwarz (htiek@cs.stanford.edu)
#
# A test harness that automatically runs your compiler on all of the tests
# in the 'samples' directory.  This should help you diagnose errors in your
# compiler and will help you gauge your progress as you're going.  It also
# will help catch any regressions you accidentally introduce later on in
# the project.
#
# That said, this test script is not designed to catch all errors and you
# will need to do your own testing.  Be sure to look over these tests
# carefully and to think over what cases are covered and, more importantly,
# what cases are not.

import os
from subprocess import *

TEST_DIRECTORY = './samples'
TESTED_DIR = './samples/'
DIFF_DIR = './samples/diff'
DONE_DIR = './samples/diff/DONE'

for _, _, files in os.walk(TEST_DIRECTORY):
  for file in files:
    if not (file.endswith('.decaf') or file.endswith('.frag')):
      continue
    refName = os.path.join(TEST_DIRECTORY, '%s.out' % file.split('.')[0])
    testName = os.path.join(TEST_DIRECTORY, file)
    testedName = os.path.join(TESTED_DIR, file)
    diffName = os.path.join(DIFF_DIR, file)


    result = Popen('./dcc < ' + testName +'>& '+ testedName +'.test ', shell = True, stderr = STDOUT, stdout = PIPE)
    result = Popen('diff ' + refName + ' '+ testedName+'.test' +' >' + diffName +'.diff ', shell = True, stdout = PIPE)
    print 'Executing test "%s"' % testName
    print ''.join(result.stdout.readlines())


for _, dirs, files in os.walk(DIFF_DIR):
  for dir in dirs:
    if not dir.endswith('DONE'):
      #print "Reading from dir:%s"% dir
      continue

    for file in files:
      #print "Verificando %s"% file
      if not (file.endswith('.diff')):
        continue
      diffName = os.path.join(DIFF_DIR, file)
      doneName = os.path.join(DONE_DIR, file)
      if( os.stat(diffName).st_size == 0):
        result = Popen('mv '+diffName+ ' '+doneName, shell = True, stderr = STDOUT, stdout = PIPE)
        print "No differences found on %s" % file
  	
