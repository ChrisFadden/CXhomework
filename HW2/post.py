import matplotlib.pyplot as plt

#Matrix multiply = 2 * m*n*p FLOPS

n = [500, 1000, 2000]

#transposition costs
# 0.0166, 0.048904, 0.131872

#Stream Benchmark
#  7216.7 MB/s

#Blocking Sizes (1000)
#  50 = 14.391
# 100 = 14.4185
# 250 = 14.4704


#********************
##Plotting Gflops
#plt.subplot(212)
#plt.plot(n, stdFlop, 'r')
#plt.plot(n, rowFlop, 'b')
#plt.plot(n, blkFlop, 'g')
#plt.ylabel("GigaFLOPS")
#plt.xlabel("Size of matrix")

#plt.savefig('Plotting.svg')
#*********************











