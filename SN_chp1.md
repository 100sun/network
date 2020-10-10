# 1.1 what is the Internet?

### inter + network

ex. mobile network, home networks, institutional networks

## component

### H/W

* **end hosts**: running network apps on terminals
* **interconnection devices**: router, switch, repeater...
    - **packet switches**: the way to communicate between hosts in the other networks
* links: copper, fiber, radio, wireless...
    - transmission rate: **bandwidth** ⬆ internet speed ⬆

### S/W

* Operating Software
* application programs
* protocols: rules for communications
    - ex. message format, order, action

<hr/>
hosts => network edges => network core

# 1.2 Network Edge

## 1.2.1 Access Networks

: make network edges(⊃ end hosts) accessible to the network

### architecture

| my network | network core | my network |
| ------------- | ------------- |------------- |
| [end host(wireless) --(wireless)--- AP --(wire)-- edge router]| (routers) | [edge router -----end host]

* transmission rate: bandwidth(bps) ⬆ internet speed ⬆
* (central office) shared / dedicated

### Digital Subscriber Line

**dedicated** access network 

0. DSL modem -> splitter
1. **DSL phone line**
2. (central office) DSL Access Multiplexer
3. voice(~4kHz): telephone network | data(4kHz~): Internet Service Provider

### Cable Network

**shared** access network 

0. cable modem -> splitter
1. **coaxial cable**: cable company provide one signal to multiple users
2. (central office) Cable Modem Termination System
3. Hybrid Fiber Coax
4. Internet Service Provider

### Home Network

0. cable or DSL modem, ONT -> splitter
1. Fiber To The Home
2. (central office) Headend
4. Internet Service Provider

### Enterprise / Institutional Network

0. AP, Ethernet switch
4. Institutional link to ISP

### Wireless Access Networks

**shared** access network 

* wireless LANs: Wireless Fidelity(shared network)
* wide-area wireless access(shared network)

## 1.2.2 Physical Media

: the physical materials that are used to store or transmit information in data communications

* guided: wired
    - Twisted-pair cable: copper wires, behind the ethernet
    - Coaxial cable: copper conductor, broadband
    - Fiber-optic Cable: high speed, low error rate
* unguided: wireless
    - radio link types

# 1.3 Network Core

* connecting network edges(⊃ end hosts) 
* the mesh of interconnected routers
* when sending packets, forwarding from a router to the next router
    - routing: Get a path from source host to destination host using routing algorithms
    - forwarding: Move packets from the before router to the next router using forwarding table

## 1.3.1 Two fundamental approaches to moving data

### comparison

| circuit switching | packet switching |
| ---------------- | ---------------- |
| call setup, resource reservation<br/> : the resources needed along a path | No call setup, no resource reservation |
| multiple users sharing a link<br/> by Frequency Division Multiplexing , Time Division Multiplexing | full link capacity<br/> by dividing into small packets which have their own each destination address<br/> using store-and-forward transmission |
| low speed | 3.5x users but after it.. low Quality Of Service |
| in telephone networks | ~ |

### store-and-forward transmission

* app in source Host ---link(by packets)---> app in destination Host
* how? storing bits until a packet and then forwarding it
* => [total time](##delay)

## 1.3.2 A Network of Networks

Internet = A Network (by ISP) of Networks (end system) 

### hierarchy structure

host < access ISP < regional ISP (peering link) < Internet eXchange Point < Tier 1 ISP or Content Provider

* content provider has its own **content provider network** in its own data center

# 1.4 Evaluation Metrics in networks

## 1.4.1 delay

: source~destination seconds

1. nodal **processing** delay: before forwarding a packet, should check its error and destination address
    - opt to the quality of router
2. **queueing** delay: when forwarding one packet, the other packet should wait in a buffer.
    - opt to the number of network users => so variable
    - **traffic intensity** = La/R ↑ ~1 infinite<br/> when packet arrival rate(packet/sec) > output link capacity(L/R) <br/> <=> over the queue -> dropped
3. **transmission** to the link delay when starting to forward: A host send a packet of ***L bits*** over a link with transmission rate ***R bits/sec***, then the time to transmit the packet is ***L/R sec***.  (link transmission rate = link capacity = link bandwidth)
    - opt to bandwidth of output link
4. **propagation** delay in the link: time = length / speed
    - opt to the amount of data
5. => end-end delay: the number of **hop** * L/R 

## 1.4.2 loss

: Packet Loss Rate (<-> Packet Delivery Rate)

* usually in router
* in a buffer when queueing delay, data > queue capacity => dropped
* host: re-transmission, network: waste of resource, user: delay

## 1.4.3 throughput

: sum of traffic <=> how much data has been moved between server and client <Br/>
=> rate: bits/time unit

1. instantaneous: throughput at the peak
2. average: throughput on the average 
    - end-end average throughput == bottleneck link == min(**R<sub>s</sub>, R<sub>c</sub>**, R/10)

# 1.5 protocol layers, service models

## Internet protocol stack

| 5 layers | explanation | protocol | encapsulation | controlled by | 
| ------- | ------- | -----|-----|-----|
| [application](./SN_chp2.md) | support network application | FTP, SMTP, HTTP | message | user(app developer) |
| **transport** | data transfer process <-> process | TCP, UDP | + segment | OS | 
| **network** | find path | IP, routing protocols | + datagram |OS | 
| **link** | data transfer by hop from source to destination | Ethernet, WiFi | + frame |OS | 
| **physical** | on the wire like cable, radio | bits | Protocol Data Unit |OS | 

* layering: modularization -> maintenance, system update
* encapsulation: message + headers..
    - source -> **switch**(link+physical) -> **router**(network+link+physical) -> destination(only *message + segment* are from source)
    -  always start from physical layer and go up by figuring out the needed info by the headers

# 1.6 networks under attack: security

# 1.7 history
