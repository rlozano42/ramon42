# Build a docker image from a Dockerfile
docker build -t <your image name> <your Dockerfile dir>

# Start an instance of a docker image
docker run -it <your image name>

# Really important if you want to bind some ports on the container to your own computer, use -p option.
# Exemple for an Apache image using port 80 in the container as our port 80
docker run -it debian:apache -p80:80

# See all images
docker images

# Delete image
docker rmi <ID>

# See running containers
docker ps

# Stop a container
docker kill <container ID>

# Delete all unused Docker images and cache and free SO MUCH SPACE on your computer
docker system prune

# Delete container
docker rm <ID>


Minikube metalldb->loadbalancer 
        Dashboard


# minikube
kubectl describe configmap config -n metallb-system

#  para saber el codigo que hay dentro de una pagina web
curl -l localhost:80

# -p pa los puertos --rm para que se vayan borrando despues de dejar de usarlo
docker run -it -p 80:80 -p 443:443 --rm --name nginx nginx 

# para escribir en la terminal de un contenedor  
docker exec -it nginx ash 