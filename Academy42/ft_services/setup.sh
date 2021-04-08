#!/bin/bash
# Resetear
# minikube delete
# killall -TERM kubectl minikube VBoxHeadless

#Inicio minikube en virtualbox
minikube start --vm-driver=virtualbox

eval $(minikube docker-env)

# kubectl proxy &

#Activamos los addons
minikube addons enable dashboard
minikube addons enable metrics-server
minikube addons enable metallb
kubectl apply -f srcs/metallb.yaml
printf "🛠 Metallb Done!\n"

# Construir imagenes  [Redireccionando el uotput a null -->  >/dev/null 2>&1]
printf "♻️ 🐳 Building Docker Images...\n"
docker build -t nginx srcs/nginx >/dev/null 2>&1
printf "🐳 🛠 Nginx Done!\n"
docker build -t wordpress srcs/wordpress >/dev/null 2>&1
printf "🐳 🛠 Wordpress Done!\n"
docker build -t mysql srcs/mysql >/dev/null 2>&1
printf "🐳 🛠 MySQL Done!\n"
docker build -t phpmyadmin srcs/phpmyadmin >/dev/null 2>&1
printf "🐳 🛠 PhpMyAdmin Done!\n"
docker build -t ftps srcs/ftps >/dev/null 2>&1
printf "🐳 🛠 Ftps Done!\n"
#docker build -t my_grafana srcs/grafana
#printf "🐳 🛠 Grafana Done!\n"
docker build -t my_influxdb srcs/influxdb
printf "🐳 🛠 InfluxDB Done!\n"
printf "✅ 🐳 Images Builded!\n"

#Ejecuto los yamls
printf "♻️ Deploying Services...\n"
kubectl apply -f srcs/nginx.yaml >/dev/null 2>&1
printf "🛠 Nginx Done!\n"
kubectl apply -f srcs/wordpress.yaml >/dev/null 2>&1
printf "🛠 Wordpress Done!\n" 
kubectl apply -f srcs/mysql.yaml >/dev/null 2>&1
printf "🛠 MySQL Done!\n"
kubectl apply -f srcs/phpmyadmin.yaml >/dev/null 2>&1
printf "🛠 PhpMyAdmin Done!\n"
kubectl apply -f ./srcs/ftps.yaml >/dev/null 2>&1
printf "🛠 Ftps Done!\n"
kubectl apply -f srcs/grafana.yaml
printf "🛠 Grafana Done!\n"
kubectl apply -f srcs/influxdb.yaml
printf "🛠 InfluxDB Done!\n"
kubectl apply -f srcs/telegraf.yaml
printf "🛠 Telegraf Done!\n"
printf "✅ Services Deployed!\n"

#Inicio el dashboard minikube
minikube dashboard