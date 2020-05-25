import os
import json
import subprocess

with open('./package.json') as f:
	data = json.load(f)

packages=data["Dependencies"]

#f=open("dep.txt","a")
list_failed=[]

for p in packages:
	cmd = 'pip install '+p
	retcode = subprocess.call(cmd,shell=True)
	print(retcode)
	if retcode==1:
		list_failed.append(p)
	#os.system(cmd)

	#f.write(p+"\n")
if len(list_failed)==0:
	print("Success")
else:
	print("Failed:")
	for x in list_failed:
		print(x)
#with open('dependency.txt', 'w') as json_file:
#	json.dump(x,json_file)
