FROM debian:buster

RUN apt update \
    && apt -y install nginx \
    && apt -y install mariadb-server \
    && apt -y install php7.3-fpm php-mysql \
    && apt -y install wget

 RUN cd /var/www/html && \ 
    wget https://wordpress.org/latest.tar.gz \
    && tar -xzvf latest.tar.gz \
    && rm -rf latest.tar.gz

RUN cd /var/www/html && \ 
    wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz \
    && tar -xzvf phpMyAdmin-5.0.1-english.tar.gz\
    && rm -rf phpMyAdmin-5.0.1-english.tar.gz\
    && mv phpMyAdmin-5.0.1-english phpMyAdmin 

COPY srcs/wp-config.php /var/www/html/wordpress
COPY srcs/config.inc.php /var/www/html/phpMyAdmin
COPY srcs/init.sql /var/
COPY srcs/default /etc/nginx/sites-available/
COPY srcs/wordpress.sql /tmp/
COPY srcs/index.html /var/www/html/

RUN service mysql start && mysql -u root mysql < /var/init.sql \
    && mysql wordpress -u root --password= < /tmp/wordpress.sql

RUN  chmod 700 /etc/ssl/private && \
	openssl req -x509 -nodes -days 365 \
	-newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" \
	-keyout /etc/ssl/private/rlozano.key \
	-out /etc/ssl/certs/rlozano.crt && \
	openssl dhparam -out /etc/nginx/dhparam.pem 1000

CMD service nginx start \
   && service  php7.3-fpm start \
   && service mysql start \
   && bash