# POTATO Paradrop

### Allows mission makers to setup a paradrop quickly and repeatedly

## What is it?

This is a framework that lets mission makers create a paradrop mission without the hassle of custom scripts. Utilising modules, it allows mission makers to setup a paradrop in seconds

## How to use?

### Step 1:

Place an `Ingress` module down. This module will define where the planes turn toward the DZ. You need to synchronise all planes that you want to paradrop units to this module. Inside this module are various settings to control the parameters of the jump.

--------------

### Step 2:

Place a `DZ` module down. This module is the start of the paradrop. Synchronise this module to the `Ingress` module (Many `DZ` modules can be synchronised to an `Ingress` module: planes will randomly select one to fly toward). After the plane crosses this point, all units within the plane will be ejected and paradropped. The planes will not deviate until all units are ejected.

-------------

### Step 3:

Place an `Egress` module down. This module is where the planes will turn toward and be deleted after they cross this point. Synchronise this module to the `Ingress` module.

## FAQ

### I want to use this dynamically during a mission!

You will have to use the scripting API to allow this, and is beyond the scope of this tutorial

### Can I paradrop cargo?

Yes! Just have an aircraft with vehicle-in-vehicle support, and the script will automatically drop the objects!

### Bailey this is so rad why did you make this. Also you are cool as hell for doing this

Cause I had this script since forever ago and wanted to integrate into POTATO. I just never got around to it until now. And thank you I didn't expect the compliment <3