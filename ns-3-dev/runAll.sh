#! /bin/bash


for protocolChoice in {5..5}
   do

   for nodeSpeed in {10..10}
      do

      for nSinks in {10..10}
         do

         for totalNodes in 50 250
            do

            echo $protocolChoice > runAllConfiguration.txt
            #echo /n >> runAllConfiguration.txt

            echo $nodeSpeed >> runAllConfiguration.txt
            #echo /n >> runAllConfiguration.txt

            echo $nSinks >> runAllConfiguration.txt
            #echo /n >> runAllConfiguration.txt

            echo $totalNodes >> runAllConfiguration.txt
            #!echo /n >> runAllConfiguration.txt

            ./waf --run manet-compare

            done
         done
      done
   done


#!echo $totalNodes > runAllConfiguration.txt
cat runAllConfiguration.txt
