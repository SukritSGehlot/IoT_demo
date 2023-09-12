

import os
from channels.routing import ProtocolTypeRouter
from Apps.demo.consumers import MyMqttConsumer  # Replace 'yourapp' with your app name
from django.core.asgi import get_asgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'yourproject.settings')  # Replace 'yourproject' with your project name

application = ProtocolTypeRouter({
    'http': get_asgi_application(),
    'mqtt': MyMqttConsumer.as_asgi(),  # Map MQTT protocol to your MQTT consumer
})
