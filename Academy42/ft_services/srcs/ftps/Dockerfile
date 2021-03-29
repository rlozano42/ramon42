FROM alpine:3.12

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf

# Installation of packages
RUN  apk update && \
			apk add vsftpd openssl

RUN  chmod 700 /etc/ssl/private && \
	openssl req -x509 -nodes -days 365 \
	-newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/O=42/CN=127.0.0.1" \
	-keyout /etc/ssl/private/vsftpd.key \
	-out /etc/ssl/certs/vsftpd.crt

EXPOSE 21 30021

ENTRYPOINT	/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf