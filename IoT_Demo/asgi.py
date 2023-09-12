"""
ASGI config for IoT_Demo project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/4.2/howto/deployment/asgi/
"""

import os
import django
from channels.routing import ProtocolTypeRouter
from Apps.demo.consumers import MyMqttConsumer
from django.core.asgi import get_asgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'IoT_Demo.settings')

application = ProtocolTypeRouter({
        'http': get_asgi_application(),
        'mqtt': MyMqttConsumer.as_asgi(),
    })