.. _user-install:

.. role:: console(code)
   :language: console

Getting started
###############

Requirements
************

- Unix-based OS
- gcc compiler with c++11 support
- CMake version >= 3.8
- Python interpreter version >= 3.4
- pip

Installation
************

The procedure for installing sdfTools is as follows:

#. Get the up-to-date version of the code:

   .. code-block:: console
      
      $ git clone git@github.com:amlucas/sdfTools.git
      
#. Compile and install the code through ``pip``
   
   .. code-block:: console
      
      $ cd sdfTools
      $ make install
         
#. Now you should be able to use sdfTools in your Python scripts:
      
   .. code-block:: python
        
      import sdfTools
   