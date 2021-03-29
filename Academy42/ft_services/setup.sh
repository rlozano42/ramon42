#Inicio minikube en virtualbox
minikube start --vm-driver=virtualbox

#kubectl proxy

minikube addons enable dashboard

#Inicio el dashboard minikube
minikube dashboard &

#Activamos la extension metallb
minikube addons enable metallb

#Ejecuto la plantilla
kubectl apply -f srcs/metallb.yaml  
minikube addons enable metrics-server

#eval $(minikube -p minikube docker-env)

#Construir imagen mysql
#docker build -t mysql ./srcs/mysql

#kubectl apply -f srcs/mysql/mysql.yaml