#!/bin/bash

echo "\x1B[36m";
echo "\n--- [ ANALYSING PUSH_SWAP] ---";
echo "\x1B[0m";

MED=700;
TRY=20;
NBRBOT=1;
NBRTOP=100;
NBR=100;
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

printf "[\033[33mNBR == $NBR && TRY == $TRY && MED == $MED\033[0m] \n"

echo "Analyse in progress ...";
while [ $IND -gt 0 ];
do
	ARG=`ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')"`
	NBRCOUP=$(./push_swap $ARG | wc -l);
	TEST=$(./push_swap $ARG | ./checker $ARG);
	if [ $TEST = "OK" ]
	then
		printf "\033[0;32m▓\033[0;0m"
		WELL=$(( $WELL + 1 ));
	else
		printf "\033[0;31m▓\033[0;0m"
	fi;

	if [ $MAX -lt $NBRCOUP ]
	then 
		MAX=$NBRCOUP; 
		ACTMAX=$ARG; 
	fi;
	if [ $MIN -eq "-1" ];
	then 
		MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	if [ $NBRCOUP -lt $MIN ]
	then MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	MOY=$(( $MOY + $NBRCOUP ));
	IND=$(( $IND - 1 ));
	if [ $NBRCOUP -gt $MED ]
	then 
		((MORE++))
	else
		((LESS++))
	fi;
done;
MOY=$(( $MOY / $TRY ));
printf "\nThere are \033[33m$WELL/$TRY\033[0m correct answers"
printf "\nThere are \033[31m$MORE\033[0m more than $MED"
printf "\nThere are \033[32m$LESS\033[0m less than $MED"
printf "\nThe biggest is:\033[32m$MAX\033[0m"
printf "\nThe average is:     \033[32m$MOY\033[0m"
printf "\nThe smallest is:\033[32m$MIN\033[0m\n"
