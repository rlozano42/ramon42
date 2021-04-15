#!/bin/bash
eval $(minikube docker-env)
kubectl delete -f influxdb.yaml
kubectl delete -f grafana.yaml
kubectl delete -f telegraf.yaml
kubectl delete -f telegraf.yaml
docker image rm -f influxdb
docker image rm -f grafana
docker image rm -f telegraf
docker system prune -f
#kubectl delete pv --all