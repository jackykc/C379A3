#!/bin/bash

# run ./350A2sh in the same directory containing
# xRun.sh, 350A2.sh, and the simul executable.
# Yea... so you have to press space bar like 36 times?
# I would do a for loop but.... nah

# seed =  0 is using time
# width, height, delay, seed, marines, tanks, rpol, bpol, bouncei
# file name is marines_rpol_bpol.txt

process=$1
# uhh this spawns 100 processes at a time so.........
page_array=( 64 128 256 512 )
window_array=( 128 256 512 1024 2048 4096 8192 16384 )

# for loop for marine/tank numbers
for i in "${page_array[@]}"
do
  echo -e "\nWe are at using PAGE SIZE of: $i"
  #read -n1 -p  "Press the spacebar to continue running script" key
  #if [ "$key" = '' ]; then echo "Continuing"; else exit; fi

  # for loop for red pol
  for j in "${window_array[@]}"
  do
      echo -e "\nWe are at using WINDOW SIZE of: $j"
    #read -n1 -p  "Press the spacebar to continue running script" key  
    #if [ "$key" = '' ]; then echo "Continuing"; else exit; fi
    
    ./$process ${i} ${j} >> ${process}_${i}_${j}_remove.txt
    #./xRun.sh 100 ./$process ${i} ${j}

    # while true
    # do
    #   read -n1 -p  "Press 'y' only after processes are done" key  
    #   if [ "$key" = 'y' ]; then 
    #     echo "${process} " > ${process}_${i}_${j}.txt
    #     grep -c "game over: RED wins" ${i}_${j}_remove.txt >> ${process}_${i}_${j}.txt
    #     break
    #   fi
    # done
    
  # end of window size loop
  done
# end of page size for loop
done

# grep to viable file
for i in "${page_array[@]}"
do
  # for loop for red pol
  for j in "${window_array[@]}"
  do
    
    echo "${process} " > ${process}_${i}_${j}_out.txt
    grep -c "game over: RED wins" ${process}_${i}_${j}_remove.txt >> ${process}_${i}_${j}_out.txt
      
  # end of window size loop
  done
# end of page size for loop
done

rm *remove.txt
rm *out*


# while :
# do
#   read -n1 -p  "Press the f only after all processes are done" key  
#   if [ "$key" = 'f' ]; then break; fi
# done

# # do the outputfiles when everything is finished
# rm *.out

# for i in "${marine_array[@]}"
# do
#   for j in 0 1 2
#   do
#     for k in 0 1 2
#     do
#       if [ $j == $k ]; then continue; fi
#       if [ $j -lt $k ]; then continue; fi
#       # output files
#       echo "Marines: $i" >> ${j}_${k}.out
#       echo "Red won: " >> ${j}_${k}.out
#       grep -c "game over: RED wins" ${i}_${j}_${k}_removeA2.txt >> ${j}_${k}.out
#       echo "Blue won: " >> ${j}_${k}.out
#       grep -c "game over: BLUE wins" ${i}_${j}_${k}_removeA2.txt >> ${j}_${k}.out
#       echo "Draws: " >> ${j}_${k}.out
#       grep -c "game over: draw" ${i}_${j}_${k}_removeA2.txt >> ${j}_${k}.out
#     done
#   done
# done
#       