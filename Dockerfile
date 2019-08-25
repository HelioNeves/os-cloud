# Use an official Ubuntu runtime as a parent image
FROM ubuntu:latest

# Ensure that all is up-to-date
RUN apt-get update && \
    apt-get -y install sudo

# Grant superuser permission to your image
RUN useradd -m docker && echo "docker:docker" | chpasswd && adduser docker sudo

# Load vim && build-essential
RUN sudo apt-get install vim -y
RUN sudo apt-get install build-essential -y

# Set user profile
USER docker

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
ADD . /app