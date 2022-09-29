import time
import threading
start = time.process_time()
threads = 10
reach = int("0x7f5b2040", base=16)
def bruteforce(thread):
    print("Thread {} started.".format(thread))
    for i in range(round(reach / threads * (thread - 1)), round(reach / threads * thread)):
        temp1 = i ^ int("0x7f5b2040", base=16)
        temp2 = temp1
        temp2 += 4
        temp2 = temp2 ^ int("0x76592353", base=16)
        if temp1 == int("0x13371337", base=16):
            print("Temp1 is matching with {}", i)
        if temp2 == int("0x13371337", base=16):
            print("Temp2 is matching with {}", i)
    else:
        print("{} ended in {}s".format(thread, time.process_time() - start))
for thread in range(1, threads + 1):
    threading.Thread(name=thread, target=bruteforce, args=[thread]).start()
