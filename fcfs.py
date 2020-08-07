def waitingTime(n, process, burstTime, wt):
    wt[0] = 0 # waiting time for the first process is 0
    for i in range(1,n): 
        wt[i] = burstTime[i-1] + wt[i-1] 

def turnAroundTime(n, process, burstTime, wt, tat):
    for i in range(n):
        tat[i] = burstTime[i] + wt[i]

def findAvgTime(n, process, burstTime):
    wt = [0]*n
    tat = [0]*n
    total_wt = 0
    total_tat = 0

    waitingTime(n, process, burstTime, wt)
    turnAroundTime(n, process, burstTime, wt, tat)

    print("No. "+"Procees burst time" + " || Waiting Time" + " || Turn around time")

    for i in range(n):
        total_wt = total_wt + wt[i]
        total_tat = total_tat + tat[i]
        print(str(i+1).ljust(3,' ')+ " " + str(burstTime[i]).ljust(22,' ') + str(wt[i]).ljust(17,' ') + str(tat[i]).ljust(15,' '))

    print("Average waiting time : " + str(total_wt/n))
    print("Average turn around time : "+ str(total_tat/n))

if __name__ == "__main__":
    
    # Reading no. of process
    n = int(input('Enter no. of processes :'))
    process = []
    burstTime = []

    # Reading process id and their burst time
    for i in range(n):
        process.append(int(input("Enter procees id :")))
        burstTime.append(int(input("Enter burst time :")))

    # Calling the findAvgTime method
    findAvgTime(n, process, burstTime)
