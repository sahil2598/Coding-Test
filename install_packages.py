import os
import json
import subprocess

with open('./package_list.json') as f:
	data = json.load(f)

packages=data["Dependencies"]

list_failed=[]

for p in packages:
	cmd = 'pip install '+p
	retcode = subprocess.call(cmd,shell=True)
	print(retcode)
	if retcode==1:
		list_failed.append(p)

if len(list_failed)==0:
	print("Success")
else:
	print("Failed:")
	for x in list_failed:
		print(x)
