# network

### scoring

### syllabus

## notes

# 1.1 what is the Internet?

### inter + network

## component

### H/W

### S/W

# 1.2 Network Edge

## 1.2.1 Access Networks

### architecture

### Digital Subscriber Line

### Cable Network

### Home Network

### Enterprise / Institutional Network

### Wireless Access Networks

## 1.2.2 Physical Media

# 1.3 Network Core

## 1.3.1 Two fundamental approaches to moving data

### comparison

### store-and-forward transmission

## 1.3.2 A Network of Networks

### hierarchy structure

# 1.4 Evaluation Metrics in networks

## 1.4.1 delay

## 1.4.2 loss

## 1.4.3 throughput

# 1.5 protocol layers, service models

## Internet protocol stack

# Chapter 2 Application Layer 83

# 2.1 principles of network applications

## App Structure

## Socket

## Addressing Processes

### host device -> (permanent 32bit **IP address + port number**(process identifier)) -> host device

## Protocol

### application layer protocol 

#### App-layer protocol defines

### underlying transport protocol

#### Transport Service Requirements

#### Internet transport protocols services

# 2.2 Web and HTTP

#### word

## HTTP response time

### non-persistent HTTP 

### persistent HTTP 

## HTTP format

### request

#### request line

#### header lines

#### body

## cookies

## how to reduce delay

### 1. origin server (+ fatter access link)

#### assumptions

#### consequences

#### total delay

### 2. origin server + local web cache

#### assumptions

#### consequences

#### total delay

#### proxy server

### 3. Conditional GET

# 2.3 Electronic mail

### Three major components

## push

### SMTP

#### transfer phases

## pull

### POP3

### IMAP

### HTTP

# 2.4 DNS

## DNS services

## how DNS works 

### by iterated query

### by recursive query

# 2.5 P2P applications

## Pure P2P architecture

## File distribution

### by [app structure](#App-Structure)

||client-server|P2P|

### BitTorrent

#### requesting chunks:

#### sending chunks

# 2.6 video streaming and content distribution networks

## CDN

### Netflix

# 3.1 transport-layer services

### transport-layer VS network-layer

### TCP VS UDP 

# 3.2 Multiplexing and Demultiplexing

## mux and demux

### demux ex

|to direct segment to appropriate socket|destination IP address<br/>destination port #|source, dest IP address<br/>source, dest port number|

## segment format

    - source port # / dest port #
    - other header fields
* transport payload:
    - application data

# 3.3 UDP

**connectionless** transport

## User Datagram Protocol

## advs of UDP

## UDP segment format

* transport payload:
    - application data

### length

= 8 bytes + length of payload 

### checksum

#### how to make checksum

# 3.4 principles of reliable data transfer

# 3.5 TCP

## segment structure

## reliable data transfer

## flow control

## connection management

# 3.6 principles of congestion control

# 3.7 TCP congestion control

# 3.7 TCP congestion control
