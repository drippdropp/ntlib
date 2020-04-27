# Number Theory Library (NTLib)

The NTlib is a collection of custom-built tools for doing research in Number Theory.

## Introduction

Much of the functionality in this collection of tools could be patched together from other sources, but, I decided to work on it from the ground up for a couple of reasons. 

First of all, I've migrated to almost exclusively using the [Julia language](https://www.julialang.org) for most of my mathematics research and data analysis work, so I wanted to get more comfortable integrating C and C++ code into my Julia code. Additionally, it's been almost a year since I was writing C and C++ code on a daily basis so I felt like it was time to sharpen my C/C++ skills and re-familiarize myself with current methodologies and best practices in the C/C++ universe.

## Features

The focus is predominately on supporting Polynomials over the Integer and Rational fields, some prime number functionality, cryptopgraphic functionality, and a few other fundamental tools I find helpful. The general plan is to combine some of my other code bases and have a central collection of tools I can utilize for my own work.

## Test-Driven Development

As a professional software engineer, I know the value of having a good suite of tests and hope to further encourage my academic colleagues to be more proactive in writing tests for their code. I am using the Boost Unit Testing framework. While some other frameworks are a little more popular, I am very comfortable with the Boost libraries in general so decided to keep it simple and leverage a library I will already be using.
