from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt

@csrf_exempt
def sort(request):
    result = open('out.json')
    return HttpResponse(result)