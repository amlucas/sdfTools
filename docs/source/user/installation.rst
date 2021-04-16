.. _user-install:

.. role:: console(code)
   :language: console

Getting started
###############

Requirements
************

- Unix-based OS
- gcc compiler with c++17 support
- CMake version >= 3.8
- Python interpreter version >= 3.4
- pip

Installation
************

The procedure for installing sdfTools is as follows:

#. Get the up-to-date version of the code:

   .. code-block:: console

      $ git clone git@github.com:amlucas/sdfTools.git --recursive

#. Compile and install the code through ``pip``

   .. code-block:: console

      $ cd sdfTools
      $ python -m pip install .

#. Now you should be able to use sdf_tools in your python scripts:

   .. code-block:: python

      import sdf_tools

Testing
*******

It is possible to test the installation by typing

   .. code-block:: console

      $ cd tests
      $ make test

.. note::

   This operation requires `atest <https://gitlab.ethz.ch/mavt-cse/atest.git>`_ to be installed on your machine
