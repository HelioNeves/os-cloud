## UFCSPA
### Operating Systems - SIO0001

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

### About

This project is intended to make a cloud version of Operating Systems (SIO0001) class from [UFCSPA - Universidade Federal de Ciências da Saúde de Porto Alegre](https://www.ufcspa.edu.br/ "UFCSPA - Universidade Federal de Ciências da Saúde de Porto Alegre").

### Project Details
#### Folders
| Folder  | Description  |
| :------------: | :------------: |
| **resources/**  |  Folder where class resources are saved  |

---

### Requirements

A **[Google Cloud Platform](https://console.cloud.google.com/?hl=pt-BR "Google Cloud Platform")** account. 

> It is free 


### Install

###### 1. Click to open this project on Google Cloud Shell :shell:

- [Google Cloud Shell](https://console.cloud.google.com/cloudshell/open?git_repo=https://github.com/HelioNeves/os-cloud "GCS") 

###### 2. Create a docker volume :cd:
> a docker volume called os

```bash
docker volume create os
```

###### 3. Basic building :wrench:

```bash
docker build . -t os-cloud
```

###### 4.  Load ubuntu layer :rainbow:
> aka: your new way to use a VM

```bash
docker run -ti --name infobio -v os:/home os-cloud bash
```

------------

##### Useful links :whale:
- [Essential Docker Commands](https://gist.github.com/HelioNeves/3b2af5eab2736eb53f70c9fcec3624ca "Essential Docker Commands") 
- [Docker lifecycle](https://medium.com/nagarwal/lifecycle-of-docker-container-d2da9f85959 "Docker lifecycle")
