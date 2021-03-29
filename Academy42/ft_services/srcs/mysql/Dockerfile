FROM alpine:3.12

COPY ./init_file /tmp/

# Se instalan todos los paquetes y dentro de mysql esta mariadb
RUN apk update 
RUN apk add mysql mysql-client openrc

RUN 	mkdir -p /run/mysqld && \
    	chown -R root:root /run/mysqld && \
		mv my.cnf /etc/

RUN     /usr/bin/mysql_install_db --datadir=/var/lib/mysql && \
        /usr/bin/mysqld --user=root --init_file=/tmp/init_file & sleep 3 && \
        /usr/bin/mysqld_safe --datadir='/var/lib/mysql'

#eso se puede meter dentro del dockerfile

EXPOSE 3306