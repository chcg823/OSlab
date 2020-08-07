def arrivalSort(n,process, arrivalTime, burstTime):
    for i in range(n):
        for j in range(n-i-1):
            if(burstTime[j] > burstTime[j+1]):
                burstTime[j], burstTime[j+1] = burstTime[j+1], burstTime[j]
                process[j], process[j+1] = process[j+1], process[j]
                arrivalTime[i], arrivalTime[j+1], arrivalTime[j+1], arrivalTime[j]

def completionSort(n, process, arrivalTime, burstTime):
    wt = [0]*n
    tat = [0]*n
    total_wt = 0
    total_tat = 0

    wt[0] = 0
    for i in range(1,n):
        wt[i] = burstTime[i-1] + wt[i-1]
    for i in range(n):
        tat[i] = burstTime[i] + wt[i]

    print("Process ID" +" || Arrival Time" +" || Procees burst time" + " || Waiting Time" + " || Turn around time")

    for i in range(n):
        total_wt = total_wt + wt[i]
        total_tat = total_tat + tat[i]
        print(str(process[i]).ljust(13,' ')+ str(arrivalTime[i]).ljust(17,' ') + str(burstTime[i]).ljust(22,' ') + str(wt[i]).ljust(17,' ') + str(tat[i]).ljust(15,' '))
    
    print("Average waiting time : " + str(total_wt/n))
    print("Average turn around time : "+ str(total_tat/n))
    




if __name__ == "__main__":
    n = int(input("Enter no. of process : "))
    process = []
    arrivalTime = []
    burstTime = []

    for i in range(n):
        process.append(input('Enter process id : '))
        arrivalTime.append(int(input('Enter arrival Time : ')))
        burstTime.append(int(input('Enter burst time : ')))
    print('Initial....')
    print("Process ID"+" || Procees burst time" + " || Arrival Time")
    for i in range(n):
        print(str(process[i]).ljust(13,' ')+ " " + str(burstTime[i]).ljust(22,' ') + str(arrivalTime[i]))
    
    arrivalSort(n, process, arrivalTime, burstTime)
    completionSort(n, process, arrivalTime, burstTime)

