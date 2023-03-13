#!/bin/sh

git status --ignored --short | grep '!!' | tr -d '! '
