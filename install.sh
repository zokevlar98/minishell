#!/bin/bash

cd ~/goinfre && mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew
brew install readline