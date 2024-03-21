FROM phusion/baseimage:focal-1.0.0
LABEL maintainer="DreamLedger Developers <dev@dreamledger.org>"
LABEL description="Dockerised DreamLedger, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /home/dreamledger

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} dreamledger && \
    useradd -u ${USER_ID} -g dreamledger -s /bin/bash -m -d /home/dreamledger dreamledger && \
    mkdir /home/dreamledger/.dreamledger && \
    chown ${USER_ID}:${GROUP_ID} -R /home/dreamledger

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER dreamledger

VOLUME ["/home/dreamledger"]

EXPOSE 16815 9999 26815 26816

WORKDIR /home/dreamledger
