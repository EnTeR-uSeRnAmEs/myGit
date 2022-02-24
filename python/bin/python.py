a = 'hello world'

n=0

import os , time

while 1:

    for i in a:
        
        if i != ' ':

            print (i,end='')
    
            time.sleep(1)

        else:

            print(i,end='')

        n += 1

    print('\b '*n,end='')

os.system('pause')
