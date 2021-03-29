FROM alpine:3.12

# Installation of packages
RUN         apk add --no-cache \
            phpmyadmin \
            nginx \
            php7 \
            php7-mysqli \
            php7-json \
            php7-mbstring \
            php7-fpm \
            php7-opcache

RUN         adduser -D -g 'www' www && \
		    mkdir -p /run/nginx www

RUN		    chown -R www:www /var/lib/nginx && \
		    chown -R www:www /www

COPY        config.inc.php /etc/phpmyadmin/config.inc.php
COPY 	    nginx.conf /etc/nginx/nginx.conf

EXPOSE      5000

ENTRYPOINT  php-fpm7 && \
            /usr/sbin/nginx -g "daemon off;"
            