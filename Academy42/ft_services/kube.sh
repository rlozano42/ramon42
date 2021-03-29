#!/bin/bash
cp -rf ~/.minikube/machines /sgoinfre/students/${USER}
rm -rf ~/.minikube/machines
ln -s /sgoinfre/students/${USER}/machines ~/.minikube/machines