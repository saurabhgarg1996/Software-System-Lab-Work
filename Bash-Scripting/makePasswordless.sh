#!/bin/bash

USERNAME=$1
HOSTNAME=$2

if [ $# -ne 2 ]; then
	echo "Incomplete Input"
	exit 0
fi

ssh-keygen -t rsa
cat ~/.ssh/id_rsa.pub | ssh $USERNAME@$HOSTNAME 'cat >> .ssh/authorized_keys'
ssh-add
ssh -o "BatchMode yes" $USERNAME@$HOSTNAME who
