
#!/usr/bin/python
# Filename: backup_ver3.py

import os
import time

# 1. The files and directories to be backed up are specified in a list
source = ["/home/airgis/dev/mycode", "/home/airgis/dev/cucb"]

# 2. The backup must be stored in a main backup directory
target_dir = '/home/airgis/backup/'

# 3. The files are backed up into a zip file
# 4. The current day is the name of the subdirectory in the main derectory
today = target_dir + time.strftime('%Y%m%d')
# The current time is the name of the zip archive
now = time.strftime('%H%M%S')

# Create the subdirectory if it isn't already there
if not os.path.exists(today):
    os.mkdir(today) #make directory
    print 'Successfully created directory', today

# Take a comment from the user to create the name of the zip file
comment = raw_input('Enter a comment --> ')
if len(comment) == 0: # check if the comment was entered
    target = today + os.sep + now + '.zip'
else:
    target = today + os.sep + now + '_' + \
        comment.replace(' ', '_') + '.zip'

# 5. We use the zip command to put the files in a zip archive
zip_command = "zip -qr '%s' %s" % (target, ' '.join(source))

# Run the backup
if os.system(zip_command) == 0:
    print 'Successful backup to', target
else:
    print 'Backup Failed'
