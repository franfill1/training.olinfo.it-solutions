#!/bin/python
import os
import json
import getpass
import requests

def main(user, pwd):
    r = requests.post('https://training.olinfo.it/api/user', headers={'Content-Type': 'application/json'}, data=json.dumps({'action': 'login', 'username': user, 'password': pwd}))
    d = r.json()

    if not d['success']:
        print('wrong username or password')
        quit()

    cookie = r.headers['Set-Cookie']
    cookie = cookie[:cookie.find(';')]

    r = requests.post('https://training.olinfo.it/api/user', headers={'Content-Type': 'application/json'}, data=json.dumps({'action': 'get', 'username': user}))
    tasks = r.json()['scores']
    solved = (task for task in tasks if task['score'] == 100)
    for task_name in (task['name'] for task in solved):
        print(task_name)

        r = requests.post('https://training.olinfo.it/api/submission', headers={'Content-Type': 'application/json', 'Cookie': cookie}, data=json.dumps({"action": "list", "task_name": task_name}))
        data = r.json()

        for submission in data['submissions']:
            if submission['score'] == 100 and len(submission['files']) == 1:
                for file in submission['files']:
                    r = requests.get(f'https://training.olinfo.it/api/files/{file["digest"]}/{file["name"]}')
                    filename = f'src/{task_name}/{task_name}.cpp'
                    os.makedirs(os.path.split(filename)[0], exist_ok=True)
                    with open(filename, 'w') as f:
                        f.write(r.text)
                break

if __name__ == '__main__':
    main(input('username: '), getpass.getpass())
