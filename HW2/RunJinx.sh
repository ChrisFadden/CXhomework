#PBS -q class
#PBS -l nodes=1:sixcore
#PBS -l walltime=00:05:00
#PBS -N FaddenMatrix
./matrix 1000 1000 1000
